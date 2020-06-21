#include "MorseConverter.Logic/Converter.h"

#include <QString>
#include <QStringList>

namespace Logic
{
    Converter::Converter()
    {
      _PopulateConvertData();
    }
    
    Converter::~Converter() = default;
    
    QString Converter::Convert(const QString& i_text) const
    {
      auto result = QString();
      
      auto words = i_text.split(' ');
      for (int word_index = 0; word_index < words.size(); ++word_index)
        {
          auto word = words[word_index];
          for (int letter_index = 0; letter_index < word.length(); ++letter_index)
            {
              auto letter = word[letter_index].toLower().toLatin1();
              if (m_convert_data.find(letter) != m_convert_data.end())
                  result += m_convert_data.at(letter);
              else
                  result += '?';
              
              if (letter_index != word.length() - 1)
                  result += ' ';
            }
          
          if (word_index != words.size() - 1)
              result += "   ";
        }
      
      return result;
    }
    
    void Converter::_PopulateConvertData()
    {
      m_convert_data = {
          { 'a', "•-" },
          { 'b', "-•••" },
          { 'c', "-•-•" },
          { 'd', "-••" },
          { 'e', "•" },
          { 'f', "••-•" },
          { 'g', "--•" },
          { 'h', "•" },
          { 'i', "•" },
          { 'j', "•---" },
          { 'k', "-•-" },
          { 'l', "•-••" },
          { 'm', "--" },
          { 'n', "-•" },
          { 'o', "---" },
          { 'p', "•--•" },
          { 'q', "--•-" },
          { 'r', "•-•" },
          { 's', "•••" },
          { 't', "-" },
          { 'u', "••-" },
          { 'v', "•••-" },
          { 'w', "•--" },
          { 'x', "-••-" },
          { 'y', "-•--" },
          { 'z', "--••" },
          { '0', "-----" },
          { '1', "•----" },
          { '2', "••---" },
          { '3', "•••--" },
          { '4', "••••-" },
          { '5', "•••••" },
          { '6', "-••••" },
          { '7', "--•••" },
          { '8', "---••" },
          { '9', "----•" }
      };
    }
}
