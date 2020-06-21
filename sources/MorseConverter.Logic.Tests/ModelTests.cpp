#include <MorseConverter.Logic/Converter.h>
#include <MorseConverter.Logic/Model.h>

#include <QPointer>

#include <gtest/gtest.h>

#include <memory>

namespace
{
    using namespace Logic;

    TEST(ModelTests, Model_is_constructible)
    {
        auto converter = std::make_unique<Converter>();
        Model model(std::move(converter));
    }

    TEST(ModelTests, Model_should_be_destroyed_as_child)
    {
        auto converter = std::make_unique<Converter>();
        auto model = std::make_unique<Model>(std::move(converter));

        QPointer<Model> new_model;
        {
            auto new_converter = std::make_unique<Converter>();
            new_model = new Model(std::move(new_converter), model.get());

            model.reset();
        }

        EXPECT_TRUE(new_model.isNull());
    }
} // namespace
