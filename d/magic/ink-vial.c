//      Vial of Writing Ink
//      Thorn@Shadowgate
//      12/2/94
//      General Wizard Class Items
//      ink-vial.c


inherit "/std/Object.c";

int uses;

void create() {
	::create();
	uses = 8;
	set_name("ink vial");
	set_id( ({ "vial", "ink", "inkx" }) );
	set_short("A vial of ink");
	set_long("A vial of ink with"+uses+" left.\n");
	set_weight(1);
	set_value(uses);
}

void set_uses(int q) { q = uses; }

int query_uses() { return uses; }

//	Note:  The special id "inkx" is important for the proper use
//	of this item with the wizard's spell book. 