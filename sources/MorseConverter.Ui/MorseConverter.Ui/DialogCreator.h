#pragma once

#include <MorseConverter.Ui/MorseConverter.Ui.API.h>

#include <memory>

class QDialog;

namespace Logic
{
    class Model;
}

namespace Ui
{
    MORSECONVERTER_UI_API std::unique_ptr<QDialog> CreateMorseConverterDialog(const Logic::Model* model);
}
