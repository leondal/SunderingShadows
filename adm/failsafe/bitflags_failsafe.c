// bitflags.c
// Code received from DreamShadow, written by Anne
// Transported to TMI by Sulam (april 12, 1992)
// rewritten because it wasn't working by sulam (april 12, 1992)
//   reimplemented all the bit stuff using bit notation

private int bitflags;	// Bitfield of flags

void set_flag(int n)
{   bitflags |= n;
}

int test_flag(int n)
{   return bitflags & n;
}

void clear_flag(int n)
{   bitflags &= ~(n);
}
