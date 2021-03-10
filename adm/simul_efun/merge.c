// merge(), brought to you by Buddha@TMI on 4-19-92
// This may look obscure.  It's for merging mappings or arrays into the 
// data structure.  Why do this? Use for back-compat-hacks like set_exits()
// that normally take two arrays. 
// Parameters: index is the mapping index to merge this stuff into.
// arg1 and arg2 are the arrays or mappings to be merged into that index.

mixed merge(mixed *arg1, mixed *arg2) {

	int i, tmp1, tmp2;
	if (!arg2) return arg1;
	if (mapp(arg1) && mapp(arg2)) return arg1 + arg2;
	else if (pointerp(arg1) && pointerp(arg2)) {
		mapping foo; 
		tmp1 = sizeof(arg1); tmp2 = sizeof(arg2);
		if (tmp1 > tmp2) tmp1 = tmp2;
		foo = allocate_mapping(tmp1);
		for (i=0;i<tmp1;i++) 
			foo[arg1[i]] = arg2[i];
		return foo; 
	}
	return 0;
}
