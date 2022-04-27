// Echo.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include <random>
#include <iostream>
#include "Echo.h"


float getRandom(float range);

namespace echo {

	float fnEcho()
	{
		__m256 avx = { 1.f, 3.f, 7.f, 4.f, 4.f, 5.f, 8.f, 5.f };
		__m256 sumTotal = { 5.f };
		sumTotal = _mm256_setzero_ps();

		__int64 N = 1 << 24;

		for (__int64 i = 0; i < N; i+= 8) {
			__m256 rands = _mm256_set_ps(getRandom(10.f), getRandom(10.f), getRandom(10.f), getRandom(10.f),
										 getRandom(10.f), getRandom(10.f), getRandom(10.f), getRandom(10.f));

			sumTotal = _mm256_add_ps(rands, sumTotal);
			
		}
		

		return sumTotal.m256_f32[0];
	}

}

float getRandom(float range) {
	int wholeNumberRange = range * 1000 + 1; // Scale range by the thousands for higher precision

	return (rand() % wholeNumberRange) * 0.002f - range;
}
