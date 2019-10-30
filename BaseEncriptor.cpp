#include "BaseEncriptor.hpp"

BaseEncriptor::~BaseEncriptor() {
    if (m_openQ) {
        (m_buffer).close();
    }
}

void BaseEncriptor::readDataFromFile() {

    std::lock_guard<std::mutex>lock(mt);
    (m_buffer).seekg(0);
    std::string line;
    (m_buffer).open(m_file, std::fstream::in);
    m_openQ = true;

    if(!(m_buffer).is_open()){
        throw("IncorrectFileError");
    }
    while (getline((m_buffer), line))
    {
        if (line.empty()) {
           continue;
        }
        m_data.emplace_back(std::move(line));
    }
    closeFile();
    m_openQ = false;
}