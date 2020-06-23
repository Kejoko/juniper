//==========================================================================================
// Core.h
//
// Keegan Kochis
// Created: 2020/6/18
// Essential definitions and global declarations to be used everywhere.
//==========================================================================================

#ifndef CORE_H
#define CORE_H

#ifdef _WIN32
#define WINDOWS_BUILD
#endif
#if defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
#define UNIX_BUILD
#endif

#endif // CORE_H
