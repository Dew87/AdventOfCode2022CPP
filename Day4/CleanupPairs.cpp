#include "CleanupPairs.h"

using namespace std;

CleanupPairs::CleanupPairs(size_t aBegin, size_t aEnd, size_t bBegin, size_t bEnd) : aBegin(aBegin), aEnd(aEnd), bBegin(bBegin), bEnd(bEnd)
{}

ostream& operator << (ostream &o, const CleanupPairs &cleanupPairs)
{
	o << cleanupPairs.aBegin << '-' << cleanupPairs.aEnd << ',' << cleanupPairs.bBegin << '-' << cleanupPairs.bEnd;
	return o;
}
