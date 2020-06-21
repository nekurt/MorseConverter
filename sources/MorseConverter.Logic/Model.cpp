#include "MorseConverter.Logic/Model.h"

#include "MorseConverter.Logic/IConverter.h"

#include <QtConcurrent>

namespace Logic
{
    Model::Model(std::unique_ptr<IConverter> i_converter, QObject *ip_parent /*= nullptr*/)
        : QObject(ip_parent)
        , m_converter(std::move(i_converter))
    {
        Q_ASSERT(m_converter);
    
        auto connection_result = connect(&m_future_watcher,
                                         &QFutureWatcher<QString>::finished,
                                         this,
                                         &Model::_TextConverted);
        Q_ASSERT(connection_result);
        Q_UNUSED(connection_result);
    }

    Model::~Model()
    {
    }

    void Model::Convert(const QString& i_text) const
    {
        auto future = QtConcurrent::run([converter = m_converter.get(),
                                         text = i_text]() {
            return converter->Convert(text);
        });
    
        m_future_watcher.setFuture(future);
    }
    
    void Model::_TextConverted()
    {
        emit textConverted(m_future_watcher.result());
    }
} // namespace Logic
