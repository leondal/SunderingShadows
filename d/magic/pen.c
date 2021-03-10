//      A Pen
//      Thorn@Shadowgate
//      12/2/94
//      General Wizard Class Items
//      pen.c


inherit "/std/Object.c";

int ink_use;

void create() {
	::create();
	set_name("pen");
	set_id( ({ "pen", "penx" }) );
	set_short("A pen");
	set_long("A writing pen");
	set_weight(1);
	set_value(5);
	ink_use = 2;
}

int query_ink_use() { return ink_use; }


//	Note:  The special id "penx" is important for the proper use
//	of this item with the wizard's spell book.