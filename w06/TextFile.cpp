#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {

    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::Line() {
        m_value = nullptr;
    }

    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (isCopy)
        {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else
        {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);

        }
    }
    void TextFile::setNoOfLines() {
        int numLine = 0;
        std::ifstream file(m_filename);
        string record;
        if (file.is_open())
        {
            while (!file.eof())
            {
                if (getline(file, record))
                {
                    numLine++;
                }
            }
            file.close();
        }
        m_noOfLines = numLine;
        if (m_noOfLines != 0)
        {
            ;
        }
        else
        {
            delete[] m_filename;
            m_filename = nullptr;
        }

    }

    void TextFile::loadText() {
        if (m_filename == nullptr)
        {
            ;
        }
        else
        {
            delete[] m_textLines;
            m_textLines = nullptr;
            m_textLines = new Line[m_noOfLines + 1];

            int numLine = 0;
            std::ifstream file(m_filename);
            string record;

            if (file.is_open()) {
                while (!file.eof())
                {
                    if (getline(file, record))
                    {
                        m_textLines[numLine] = record.c_str();
                        numLine++;
                    }

                }

                m_noOfLines = numLine;
            }

            file.close();
        }

    }

    void TextFile::saveAs(const char* fileName)const {
        std::ofstream file(fileName);


        if (file.is_open())
        {
            for (unsigned int i = 0; i < m_noOfLines; i++)
            {
                file << m_textLines[i];
                file << "\n";
            }
        }
        file.close();

    }

    TextFile::TextFile(unsigned pageSize) {
        m_pageSize = pageSize;
        m_noOfLines = 0;
        m_filename = nullptr;
        m_textLines = nullptr;
        
       
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_pageSize = pageSize;
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;

        if (filename == nullptr)
        {
            ;
        }
        else
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& obj) {
        m_pageSize = obj.m_pageSize;
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
       

        if (obj.m_filename != nullptr)
        {
            setFilename(obj.m_filename, true);
            obj.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& obj) {
        if (*this && obj.m_filename != nullptr)
        {

            delete[] m_textLines;
            m_textLines = nullptr;
            obj.saveAs(m_filename);
            setNoOfLines();
            loadText();

        }
        return *this;
    }


    TextFile::~TextFile() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_textLines;
        m_textLines = nullptr;
        m_pageSize = 0;
        m_noOfLines = 0;
        
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }


    std::ostream& TextFile::view(std::ostream& ostr)const {
        if (*this)
        {
            ostr << m_filename << endl;
            ostr.fill('=');
            ostr.width(strLen(m_filename));
            ostr << "" << endl;
            int i = 0;
            while (i < (int)m_noOfLines)
            {
                ostr << m_textLines[i].m_value << endl;

                if ((i + 1) % m_pageSize != 0)
                {
                    ;
                }
                else
                {
                    cout << "Hit ENTER to continue...";
                    char newline;
                    cin.get(newline);
                    while (newline != '\n') {
                        if (newline != '\n')
                        {
                            ;
                        }
                    }
                }
                i++;
            }
        }

        return ostr;
    }

    const char* TextFile::operator[](unsigned index)const {
        char* getLine;
        int recordInd = index;
        if (*this)
        {
            while (recordInd >= (int)m_noOfLines)
            {
                if (recordInd < (int)m_noOfLines)
                {
                    ;
                }
                else
                {
                    recordInd = recordInd - (int)m_noOfLines;;
                }
            };

            getLine = m_textLines[recordInd].m_value;
        }
        else
        {
            getLine = nullptr;
        }

        return getLine;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string filename;
        getline(istr, filename);
        m_filename = new char[strLen(filename.c_str()) + 1];
        strCpy(m_filename, filename.c_str());
        setNoOfLines();
        loadText();

        return istr;
    }

    TextFile::operator bool()const {
        return (m_filename != nullptr);
    }

    const char* TextFile::name()const {
        return m_filename;
    }

    std::ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);

        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        text.getFile(istr);

        return istr;
    }
}