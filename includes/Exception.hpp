/*
** EPSI PROJECT, 2020
** Exception.hpp
** File description:
** Exception header
*/

#ifndef EXCEPTION_HPP_
    #define EXCEPTION_HPP_

#include <exception>
#include <string>

namespace vchips
{
    class NTSError : public std::exception {
        public:
            NTSError(const std::string &message);
            const char *what() const noexcept final { return _message.c_str(); };
        private:
            std::string _message;
    };

    class ArgsError : public NTSError {
        public:
            ArgsError(const std::string &message);
        private:
    };

    class FileError : public ArgsError {
        public:
            FileError(const std::string &message);
        private:
    };

    class SyntaxError : public ArgsError {
        public:
            SyntaxError(const std::string &message);
        private:
    };
}

#endif /* EXCEPTON_HPP_ */
