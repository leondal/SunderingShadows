// copy() is brought to you by Buddha@tmi-2!
// It's expensive! Don't use it if you don't have to!

/**
 * @file
 */

/**
 * This is used to create a duplicate mapping or array that doesn't hold
 * any insecure pointers to other ones.
 */
mixed copy(mixed var) {
	mixed res;
	int i;

	if (mapp(var)) {
		mixed *index;
		res = ([ ]);
		index = keys(var);
		for (i=0;i<sizeof(index);i++)
			res[index[i]] = copy(var[index[i]]);
		return res;
	}
	else if (pointerp(var)) {
		res = allocate(sizeof(var));
		for (i=0;i<sizeof(var);i++)
			res[i] = copy(var[i]);
		return res;
	}
	else return var;
}
