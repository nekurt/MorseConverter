#include <MorseConverter.Logic/Converter.h>

#include <gtest/gtest.h>

namespace
{
    using namespace Logic;

    TEST(ConverterTests, Converter_is_constructible)
    {
        Converter converter;
    }

    TEST(ConverterTests, Convert_should_return_morse_code_for_one_letter)
    {
        Converter converter;
        EXPECT_EQ("•-", converter.Convert("a"));
    }
    
    TEST(ConverterTests, Convert_should_return_morse_code_with_one_space_between_letters)
    {
        Converter converter;
        EXPECT_EQ("•- -•••", converter.Convert("ab"));
    }

    TEST(ConverterTests, Convert_should_return_morse_code_with_three_spaces_between_words)
    {
        Converter converter;
        EXPECT_EQ("•-   -•••", converter.Convert("a b"));
    }
    
    TEST(ConverterTests, Convert_should_return_morse_code_with_one_and_three_spaces)
    {
        Converter converter;
        EXPECT_EQ("•- -•••   •-", converter.Convert("ab a"));
    }
    
    TEST(ConverterTests, Convert_should_return_morse_code_for_uppercase_text)
    {
        Converter converter;
        EXPECT_EQ("••• --- •••", converter.Convert("SOS"));
    }
    
    TEST(ConverterTests, Convert_should_return_question_mark_for_unsupported_letters)
    {
        Converter converter;
        EXPECT_EQ("-•-- --- ?", converter.Convert("Yo!"));
    }
} // namespace
