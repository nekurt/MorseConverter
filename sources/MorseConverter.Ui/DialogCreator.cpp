#include "MorseConverter.Ui/DialogCreator.h"

#include "ui_MorseConverterWidget.h"

#include <MorseConverter.Logic/Model.h>

#include <QDialog>

namespace Ui
{
    std::unique_ptr<QDialog> CreateMorseConverterDialog(const Logic::Model* model)
    {        
        auto dialog = std::make_unique<QDialog>();
        dialog->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
        
        Ui::MorseConverterWidget ui;
        ui.setupUi(dialog.get());

        auto connection_result = QObject::connect(ui.mp_edit_input,
                                                  &QPlainTextEdit::textChanged,
                                                  dialog.get(),
                                                  [input = ui.mp_edit_input,
                                                   model]() {
            model->Convert(input->toPlainText());
        });
        Q_ASSERT(connection_result);

        connection_result = QObject::connect(model,
                                             &Logic::Model::textConverted,
                                             ui.mp_edit_morse,
                                             &QPlainTextEdit::setPlainText);
        Q_ASSERT(connection_result);
        Q_UNUSED(connection_result);

      return dialog;
    }
} // namespace UI
