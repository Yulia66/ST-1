// Copyright 2025 UNN-IASR
#include <cstdint>
#include <vector>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value < 2ULL) {
        return false;
    }
    
    if (value > 2ULL && (value & 1ULL) == 0ULL) {
        return false;
    }
    
    uint64_t limit = static_cast<uint64_t>(std::sqrt(static_cast<long double>(value)));
    for (uint64_t divisor = 3ULL; divisor <= limit; divisor += 2ULL) {
        if (value % divisor == 0ULL) {
            return false;
        }
    }
    
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0ULL) {
        return 0ULL;
    }
    
    uint64_t counter = 0ULL;
    uint64_t candidate = 1ULL;
    
    while (counter < n) {
        ++candidate;
        if (checkPrime(candidate)) {
            ++counter;
        }
    }
    
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    if (value == UINT64_MAX) {
        return 0ULL;
    }
    
    uint64_t search = value + 1ULL;
    while (!checkPrime(search)) {
        ++search;
    }
    
    return search;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2ULL) {
        return 0ULL;
    }
    
    std::vector<bool> sieve(hbound, true);
    sieve[0] = sieve[1] = false;
    
    uint64_t sqrtBound = static_cast<uint64_t>(std::sqrt(static_cast<long double>(hbound)));
    
    for (uint64_t p = 2ULL; p <= sqrtBound; ++p) {
        if (sieve[p]) {
            for (uint64_t multiple = p * p; multiple < hbound; multiple += p) {
                sieve[multiple] = false;
            }
        }
    }
    
    uint64_t total = 0ULL;
    for (uint64_t num = 2ULL; num < hbound; ++num) {
        if (sieve[num]) {
            total += num;
        }
    }
    
    return total;
}