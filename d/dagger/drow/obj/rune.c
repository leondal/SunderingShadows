#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"rune","rune of water"}));
    set_short("%^BOLD%^%^BLUE%^Rune of water%^RESET%^");
    set_long("This rune object is simply made of solidified water. The object is "
	"covered in ancient glyphs. While the meanings of the glyphs are not clear "
	"you know that you can place the rune onto a surface by <place rune>. "
    );
    set_weight(1);
}
