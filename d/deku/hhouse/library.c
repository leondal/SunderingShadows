#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long(
@KAYLA
You can tell that this room was once a library, with bookshelves 
around the walls.  Most of the bookshelves are broken now and in
many places have come away from the wall altogether.  Those few
shelves still intact are empty but there is a pile of books in
the southwest corner.
KAYLA
    );
    set_exits(([ "north" : HH_ROOMS+"hall1i"  ] ));
    set_items(([
       "books" : "There are 14 books in the pile untidily thrown into the corner. "
          "They are now covered with cobwebs, vermin droppings and mold.  They "
          "don't seem to have any value."
    ] ));
    hauntings();
}

void reset() {
  ::reset();
}
