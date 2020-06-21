#include <MorseConverter.Logic/Converter.h>
#include <MorseConverter.Logic/Model.h>

#include <MorseConverter.Ui/DialogCreator.h>

#include <QApplication>
#include <QDIalog>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    auto converter = std::make_unique<Logic::Converter>();
    auto model = std::make_unique<Logic::Model>(std::move(converter));

    auto dialog = Ui::CreateMorseConverterDialog(model.get());

    dialog->show();

    return app.exec();
}
