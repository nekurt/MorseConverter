#pragma once

#include <QString>

namespace Logic
{
    class IConverter
    {
        public:
            virtual ~IConverter() = default;

            virtual QString Convert(const QString& i_text) const = 0;
    };
}
