/*
** EPSI PROJECT, 2020
** Exception.cpp
** File description:
** Exception implementation
*/

#include "Exception.hpp"

vchips::NTSError::NTSError(const std::string &message) : _message(message)
{}

vchips::ArgsError::ArgsError(const std::string &message) : NTSError(message)
{}

vchips::FileError::FileError(const std::string &message) : ArgsError(message)
{}

vchips::SyntaxError::SyntaxError(const std::string &message) : ArgsError(message)
{}
