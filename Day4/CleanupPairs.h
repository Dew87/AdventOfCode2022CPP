#ifndef CLEANUP_PAIRS_H
#define CLEANUP_PAIRS_H

#include <ostream>

struct CleanupPairs
{
	CleanupPairs(size_t aBegin, size_t aEnd, size_t bBegin, size_t bEnd);

	size_t aBegin;
	size_t aEnd;
	size_t bBegin;
	size_t bEnd;
};

std::ostream& operator << (std::ostream &o, const CleanupPairs &cleanupPairs);

#endif
