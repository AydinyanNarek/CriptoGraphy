#ifndef __BASEENCRIPTOR__
#define __BASEENCRIPTOR__
#include <string_view>
#include <string>
#include <vector>
#include <fstream>
#include <mutex>

class BaseEncriptor {

protected:
    explicit BaseEncriptor(std::string_view file) : m_file(file) {}
    BaseEncriptor() = default;
    ~BaseEncriptor();

    /**
     *   @brief Get data from file already stored in std::vector of std::string
     *   @param[in] file_name - input file
    **/
    const std::vector<std::string>& getData() const { return m_data; }

private:
    /**
     *   @brief Reads data from file and stors in std::vector
    **/
    void readDataFromFile();

    /**
     *   @brief Close already opend stream
    **/
    inline void closeFile() { (m_buffer).close();}
    
protected:
    std::vector<std::string> m_data;
    std::fstream m_buffer{nullptr};
    std::string m_file;
    bool m_openQ{false};
    std::mutex mt;
};


#endif //__BASEENCRIPTOR__