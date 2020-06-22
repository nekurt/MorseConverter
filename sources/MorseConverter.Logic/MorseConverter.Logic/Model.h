#pragma once

#include <MorseConverter.Logic/MorseConverter.Logic.API.h>

#include <QFutureWatcher>
#include <QObject>

#include <memory>

namespace Logic
{
    class IConverter;
    
    class MORSECONVERTER_LOGIC_API Model : public QObject
    {
        Q_OBJECT

        public:
            Model(std::unique_ptr<IConverter> i_converter, QObject* ip_parent = nullptr);
            ~Model() override;

            void Convert(const QString& i_text) const;

        signals:
            void textConverted(QString i_text_converted) const;

        protected:
            void _TextConverted();

        private:
            std::unique_ptr<IConverter> m_converter;
            mutable QFutureWatcher<QString> m_future_watcher;
    };
}
