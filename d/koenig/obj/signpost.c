#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("Sign Post");
  set_id( ({"sign", "sign post"}) );
  set_short("A Sign Post");
set_long("\n\n\n\n%^BOLD%^%^WHITE%^--== Welcome to Muileann ==--\n\nKnock on the gates to be granted access.%^RESET%^\n\n\n%^RED%^*Scrawled into the bottom of the sign, someone has added: %^BOLD%^Turn back while you still can!%^RESET%^");

/*While the below holds a nice sentiment, it makes for poor immersion and says a lot of information that is no longer relevant. Titania 12/16/2019
  set_long(
@PEGASUS
  This area was coded by Pegasus with the help and suggestions of others
and she would like to give special thanks to the following people:
  Hern          Grayhawk          Firedragon       Tristan        Vashkar
  Thorn         Reboot            Gilgamesh        Tuco           Indigo
  Bounce        Lews              Bane             Magnus         Santana
  Menolly       Scythe
  This sign post is also to let the players know that since the crash there
have been some major changes made in the town of Muileann. It has become
level restricted and more monsters have been added. There are also some
neat quirks in now too. The high mortal area was lost in the crash and is
being rebuilt but will no longer connect to Muileann so please have
patience and keep your eyes peeled. Have fun and enjoy!
PEGASUS

  If you have any suggestions or worries or even complaints over this area
please mail Pegasus.
*/

  set_weight(10000);
  set_value(0);
}

int __Read(string str)
{
    if(str == "sign")
    {
        TP->force_me("look sign");
        return 1;
    }
}
