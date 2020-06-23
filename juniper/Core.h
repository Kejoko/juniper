//==========================================================================================
// Core.h
//
// Keegan Kochis
// Created: 2020/6/22
// Essential definitions and global declarations to be used everywhere.
//==========================================================================================

#ifndef CORE_H
#define CORE_H

#ifdef _WIN32
#define WINDOWS_BUILD
#define FUNC_STRING __FUNCSIG__
#endif

#if defined(unix) || defined(__unix) || defined(__unix__)
#define LINUX_BUILD
#endif

#ifdef __APPLE__
#define MAC_BUILD
#endif

#if defined(LINUX_BUILD) || defined(MAC_BUILD)
#define UNIX_BUILD
#define FUNC_STRING __PRETTY_FUNCTION__
#endif

#endif // CORE_H
