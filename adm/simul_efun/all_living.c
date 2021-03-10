//all_living.c

//to return all the living contents of an object.

object *all_living(object room){
	object *inven,*tmp;
	int i, j;
	if(!objectp(room)) return ({});
	tmp = ({});
	inven = all_inventory(room);
	j = sizeof(inven);
	for(i=0;i<j;i++)
		if(living(inven[i]))
			tmp += ({inven[i]});
	
	return tmp;
}
