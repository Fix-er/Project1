#pragma once

template < typename T >
size_t ObjCounter = 0;

template < typename T >
struct CountThis
{
    CountThis() { ++ObjCounter< T >; }
    CountThis(const CountThis&) { ++ObjCounter< T >; }
    CountThis(CountThis&&) { ++ObjCounter< T >; }
    CountThis& operator=(const CountThis&) = default;
    CountThis& operator=(CountThis&&) = default;
    ~CountThis() = default;

    static size_t get() { return ObjCounter< T >; }
    static void   reset() { ObjCounter< T > = 0; }
};