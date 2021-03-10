inherit "/d/common/obj/misc/chesti.c";

void create()
{
	::create();
	create_treasure_chest("random", "random");
}

int is_carving(){return 1;}
