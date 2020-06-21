#pragma once

#include <MorseConverter.Logic/MorseConverter.Logic.API.h>

#include <MorseConverter.Logic/IConverter.h>

#include <unordered_map>

namespace Logic
{
    class Converter : public IConverter
    {
        public:
            MORSECONVERTER_LOGIC_API Converter();
            MORSECONVERTER_LOGIC_API ~Converter() override;

            MORSECONVERTER_LOGIC_API QString Convert(const QString& i_text) const override;

        private:
            void _PopulateConvertData();

        private:
            std::unordered_map<char, QString> m_convert_data;
    };
}
