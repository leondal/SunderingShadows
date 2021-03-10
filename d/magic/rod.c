inherit "/std/Object.c";
#define TPQCN this_player()->query_cap_name()

create() {
   set_name("bestower");
   set_id(( { "bestower", "rod" }));
   set_short("A rod");
   set_weight(10000);
   set_long("type 'bestow <player name>'\n");
}

init() {
	::init();
	add_action("bestow", "bestow");
}

bestow(string str) {
	object magicbook;
	mixed bookid;	
	bookid = str+time();
	magicbook = new("/d/magic/magic_book");
	magicbook->set_id( ({ "book", "bookx", bookid }) );
	magicbook->set_book_id(bookid);
	magicbook->move(this_player());
	write("Book created with book id: "+bookid);
	write_file("/d/magic/spellbook/"+bookid, "Spell Book created for "+TPQCN+" at "+ctime(time())+".\nBook ID = "+bookid+"\n");
}
	
	