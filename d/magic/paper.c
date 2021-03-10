//      Piece of Paper for Copying Spells on
//      Thorn@Shadowgate
//      12/2/94
//      General Wizard Class Items
//      paper.c


inherit "/std/Object.c";

void create() {
	::create();
	set_name("paper");
	set_id( ({ "paper", "paperx" }) );
	set_short("A piece of paper");
	set_long("A piece of paper perfect for writing spells on");
	set_weight(1);
	set_value(2);
}

//	Note:  The special id "paperx" is important for the proper use
//	of this item with the wizard's spell book.