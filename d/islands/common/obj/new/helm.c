#include <std.h>
#include <daemons.h>
#include <clock.h>

inherit "/d/common/obj/armour/helm";
int uses_per_day = 50, used, end_day;

void create()
{
    ::create();
    set_name("helm of true seeing");

    set_id(({ "helm", "helm of true seeing", "black iron helm", "cold black iron helm" }));

    set_obvious_short("%^BOLD%^%^BLACK%^A cold black iron helm adorned with %^BLUE%^sapphires%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^Helm of %^BLUE%^T%^CYAN%^r%^RESET%^%^CYAN%^u%^BLUE%^e %^BOLD%^S%^BOLD%^%^CYAN%^ee%^BOLD%^%^BLUE%^ing%^RESET%^");

    set_long("%^CYAN%^This helm is made from %^BOLD%^%^BLACK%^cold black iron%^RESET%^%^CYAN%^" +
             ". The design is small and compact, with a streamline styling. The top of the helm is" +
             " smooth and without decoration, as is much of the helm, save for the faceguard." +
             " The %^BOLD%^%^BLACK%^iron %^RESET%^%^CYAN%^rolls down to fit over the forehead," +
             " eyes, and nose of the wearer. %^BOLD%^%^BLUE%^S%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p" +
             "%^BOLD%^h%^CYAN%^i%^RESET%^%^CYAN%^e%^BLUE%^s%^CYAN%^ are set into two sockets that " +
             "you would imagine is made for the eyes to see through, but you could not imagine how." +
             " Where the metal stops over the nose is the extent of the protection for the face, as " +
             "the rest is left open so the wearer can be heard when speaking.%^RESET%^");

    set_lore("This is the Helm of True Sight. Created by the mercenary Alvin Cortnint. He made " +
             "several in order to keep his employees well equiped to deal with other wizards. The " +
             "key word to the true power of this helm was true, the rest you do not " +
             "remember.");

    set_property("lore difficulty", 12);

    set_property("no curse", 1);
    set_property("enchantment", 7);
    set_item_bonus("sight bonus", 7);
    set_item_bonus("perception", 6);

    set_value(150000);
    set_wear((: TO, "wearme" :));
    set_remove((: TO, "removeme" :));

    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required", 35);
}

void init()
{
    ::init();
    add_action("true", "true");

    add_action("look_at", "look");
    if (objectp(ETO) && living(ETO)) {
        set_size(ETO->query_size());
    }
}

int true(string str)
{
  if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info", TP);
      return 0;
  }

  if (!query_worn()) {
      return notify_fail("Wear it first.\n");
  }
  if (!end_day) {
      end_day = time() + DAY;
  }
  if (end_day) {
      if (time() < end_day) {

        if (!str) {
            return notify_fail("True what?\n");
        }
        if (str != "seeing") {
            return notify_fail("You cannot call upon the powers of true " + str + "!\n");
        }
          if (used < uses_per_day) {
              if (new("/cmds/spells/t/_true_seeing")->use_spell(TP, TP, 50, 100, "mage")) {
                  tell_room(ETO, "%^BOLD%^%^BLUE%^The sapphires in the helmet shimmer briefly.", TO);
                  used++;
                  tell_object(ETO, "Used " + used + " of " + uses_per_day + " uses per day.");
              }
          }else if (used >= uses_per_day) {
              tell_object(ETO, "The magic has been drained from the helm, it needs time "
                          "to recharge.");
              return 1;
          }
      }
      if (time() > end_day) {
          end_day = time() + DAY;
          used = 0;
      }
  }
  return 1;
}

int wearme()
{
    tell_object(ETO, "%^BOLD%^%^BLUE%^You now see the world" +
                " through the sapphires and everything is clear.");
    return 1;
}

int removeme()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^As you remove the helm the world" +
                " becomes a shadowed mystery again.");
    return 1;
}

int look_at(string str)
{
    if (!query_worn()) {
        return 0;
    }else {
        tell_object(ETO, "%^BOLD%^%^BLACK%^You see everything in shades" +
                    " of %^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^.");
        return 0;
    }
}
