//Cythera - Magic Vestments 6/05
//Added Anhur ~Circe~ 5/27/8
//Added Silvanus - N, 3/13.
// set to medium armor prof as kids were getting baffled why they wouldn't stack with bracers. N, 3/11
#include <std.h>
inherit ARMOUR;
string owner;

void create()
{
    ::create();
    set_name("vestments");
    set_id(({ "vestments", "magical vestments", "vestment" }));
    set_short("vestments");
    set_long("These are vestments.  They will be of your faith.");
    set_type("chain");
    set_limbs(({ "torso" }));
    set_armor_prof("medium");
    set_weight(15);
    set_value(0);
    set_ac(5);
    set_wear((: TO, "wearit" :));
    set_remove((: TO, "removeit" :));
    //set_property("enchantment",1);
    //if(TO->query_property("enchantment")< 1){
    //   remove_property("enchantment");
    //   set_property("enchantment",1);
    // }
}

void init()
{
    int clevel;
    ::init();
    if (stringp(owner)) {
        return;
    }
    if (interactive(TP) && TP == ETO) {
        owner = TPQN;
    }
    clevel = ETO->query_guild_level("cleric");
    set_property("enchantment", clevel / 10);
    while ((int)(query_property("enchantment")) < 0) {
        remove_property("enchantment");
        set_property("enchantment", clevel / 10);
    }
}

int query_size()
{
    if (living(ETO)) {
        return ETO->query_size();
    }else {
        return 3;
    }
}

int wearit()
{
    string deity, rankhue;
    int myac, mylvl;
    if (!objectp(ETO)) {
        return 1;
    }
    mylvl = ETO->query_guild_level("cleric");
    deity = ETO->query_diety();
    // switch(mylvl){
    //    case 0: myac = 0; break;
    //    case 1..10:  myac = 4; break;
    //    case 11..20:  myac = 5; break;
    //    case 21..30:  myac = 6; break;
    //    case 31..40:  myac = 7; break;
    //    default: myac = 8; break;
    //}
    switch (deity) {
    case "lysara": set_long("%^BOLD%^%^BLACK%^Flowing gray silk%^RESET%^" +
                            " is used in the creation of these vestments.  They are loosely fitted," +
                            " making them quite comfortable.  While mostly plain, a carefully stitched" +
                            " hem lines the throat in darker gray, while one wrist is encircled in" +
                            " %^BOLD%^%^WHITE%^white %^RESET%^and the other in %^BOLD%^%^BLACK%^black" +
                            "%^RESET%^.  The lower length of the garment simply fades away in gradual" +
                            " ripples of soft silk, like mist dissipating in the air.");
        set_short("%^BOLD%^%^BLACK%^Flowing gray silk vestments%^RESET%^");
        break;

    case "lord shadow": set_long("%^BOLD%^%^BLACK%^Plush black velvet%^RESET%^" +
                                 " makes up these voluminous vestments.  The vestments are cut full, to" +
                                 " allow of the priest to easily blend into the night and move as " +
                                 "silently as possible.  Minute %^CYAN%^azure%^RESET%^ colored" +
                                 " piping trims the vestments, giving a subtle hint of color that " +
                                 "only seems to deepen the darkness of the garments.  The vestments" +
                                 " are made with full sweeping sleeves that flow over the priests hands." +
                                 "  A large %^BOLD%^%^CYAN%^diamond %^RESET%^has been stitched at " +
                                 "the centre of the garment, above the breastbone.");
        set_short("%^BOLD%^%^BLACK%^Plush black velvet vestments%^RESET%^");
        break;

    case "nimnavanon": set_long("These vestments are simple and unassuming, made " +
                                "of old hides in shades of %^ORANGE%^dusty brown%^RESET%^.  They are loosely " +
                                "cut to afford an ease of movement, but thick enough to deflect rough foliage " +
                                "and thorns.  Small, %^BOLD%^%^BLACK%^d%^RESET%^u%^ORANGE%^l%^BOLD%^%^BLACK%^l " +
                                "%^RESET%^feathers hang from the collar and sleeves, swaying with the wearer's " +
                                "movements.  Upon the breast, the vestments bear the image of a %^BOLD%^%^BLACK%^" +
                                "wolf's pawprint%^RESET%^.");
        set_short("%^RESET%^%^ORANGE%^Dull hide vestments adorned with %^BOLD%^%^BLACK%^f" +
                  "%^RESET%^e%^ORANGE%^a%^RESET%^t%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^e%^RESET%^r" +
                  "%^ORANGE%^s%^RESET%^");
        break;

    case "jarmila": set_long("%^BOLD%^%^WHITE%^Pristine ivory%^RESET%^ velvet" +
                             " and silk have been fashioned into these vestments.  The vestments are cut" +
                             " in a fashion to show off the best features of the wearer, and minimize any" +
                             " flaws.  Armbands made from %^YELLOW%^gold%^RESET%^ filigree rest over each" +
                             " sleeve, adding an artistic touch to the aesthetically pleasing vestments.  " +
                             "Above the left breast, embroidered in %^RED%^crimson%^RESET%^, is a beautiful rose.");
        set_short("%^YELLOW%^G%^RESET%^%^ORANGE%^ol%^YELLOW%^d-he%^RESET%^%^ORANGE%^mm" +
                  "%^YELLOW%^ed %^BOLD%^%^WHITE%^ivory vestments%^RESET%^");
        break;

    case "kismet": rankhue = "%^GREEN%^Green";
        if (mylvl > 10) {
            rankhue = "%^YELLOW%^Yellow";
        }
        if (mylvl > 20) {
            rankhue = "%^ORANGE%^Orange";
        }
        if (mylvl > 30) {
            rankhue = "%^RED%^Crimson";
        }
        if (mylvl > 40) {
            rankhue = "%^MAGENTA%^Indigo";
        }
        set_long("%^BOLD%^Pale white%^RESET%^ heavy" +
                 " silk has been fashioned into these vestments.  The pale " +
                 "silk has a slight %^BOLD%^white%^RESET%^ seen to it, giving" +
                 " it an opalescent look.  The flowing vestments have a " +
                 "fashionable silhouette to them, in a way that seems timeless" +
                 ".  " + rankhue + "%^RESET%^ bands trim the hem and flowing sleeves of the " +
                 "vestments, signifying the status of the wearer.%^RESET%^");
        set_short("%^BOLD%^%^WHITE%^Pale white silk vestments%^RESET%^");
        break;

    case "ryorik": set_long("%^BOLD%^%^BLACK%^Metallic black satin%^RESET%^" +
                            " is used to fashion these vestments.  The black satin shimmers " +
                            "chaotically in the light, giving the vestments a wild look.  " +
                            "The vestments are cut with a jagged pattern all over, as if trying" +
                            " to mirror bolts of lighting.  The edges of the vestments are " +
                            "finished off with %^BOLD%^silvery %^YELLOW%^gold %^RESET%^cloth" +
                            " that helps to further give the illusion as if they are made of lightning.");
        set_short("%^BOLD%^%^BLACK%^Metallic black satin vestments%^RESET%^");
        break;

    case "callamir": set_long("%^BOLD%^%^CYAN%^Sky-blue cotton" +
                              "%^RESET%^ is used in the creation of these comfortable vestments.  Not" +
                              " a robe as one would expect, the outfit instead is made up" +
                              " of a long-sleeved shirt and pants, with a slight fashionable look" +
                              " to them, in a roguish sort of way.  Around the wrists and hem of" +
                              " the vestments, %^BOLD%^silver" +
                              "%^RESET%^ bands trim the edges. Within the silver band images of" +
                              " cards, dice, shamrocks and rabbits can be found, all totems of" +
                              " good fortune.");
        set_short("%^BOLD%^%^CYAN%^Sky-blue cotton vestments%^RESET%^");
        break;

    case "nilith": set_long("Crafted from %^BOLD%^%^BLACK%^black cotton" +
                            "%^RESET%^ these %^BOLD%^%^MAGENTA%^mauve%^RESET%^ and %^RED%^red" +
                            "%^RESET%^ streaked vestments have a chaotic look to them.  The " +
                            "vestments are fitted through the torso but flare outwards at the " +
                            "hips into voluminous folds.  Bi-colored sleeves lace onto the main " +
                            "body of the vestments.  The left sleeve is made with %^RED%^deep red" +
                            "%^RESET%^ and %^BOLD%^%^BLACK%^black cotton%^RESET%^, while the right" +
                            " features a %^BOLD%^%^MAGENTA%^mauve%^RESET%^ and %^BOLD%^%^BLACK%^black" +
                            "%^RESET%^ color scheme.  A %^BOLD%^%^BLACK%^lacquered belt%^RESET%^" +
                            " shaped to resemble blackened bones rests around the midsection" +
                            " of the vestments.");
        set_short("%^BOLD%^%^BLACK%^Black cotton %^MAGENTA%^s%^RED%^t%^MAGENTA%^r" +
                  "%^RED%^e%^MAGENTA%^a%^RED%^k%^MAGENTA%^e%^RED%^d%^BLACK%^ vestments%^RESET%^");
        break;

    case "kreysneothosies": set_long("The vestments of Kreysneothosies are " +
                                     "fashioned from crisp linen.  %^BOLD%^%^WHITE%^White %^RESET%^serwal " +
                                     "pants are only seen at the ankles, mostly covered by the " +
                                     "%^BOLD%^%^BLACK%^black thawb robe%^RESET%^.  The tailored and " +
                                     "structured pristine linen has a stylish appeal to it.  " +
                                     "The vestments bear a long v-shaped cut down the front, beneath which " +
                                     "sits a stiffened %^YELLOW%^golden collar%^RESET%^.");
        set_short("%^BOLD%^%^WHITE%^Crisp linen vestments%^RESET%^");
        break;

    case "the faceless one": set_long("%^BOLD%^%^BLACK%^Dark gray %^RESET%^silk" +
                                      " is used in the creation of these vestments.  The long flowing" +
                                      " vestments are made in a way to allow the priest to easily blend" +
                                      " in with the shadows around them.  The shapeless vestments bear" +
                                      " no trim or decoration that would make them distinctive.  A hood" +
                                      " attached at the collar could be raised to %^BLUE%^shroud %^RESET%^the" +
                                      " wearer's features.");
        set_short("%^BOLD%^%^BLACK%^Dark gray silken vestments%^RESET%^");
        break;

    case "cevahir":
        set_long("%^BOLD%^%^WHITE%^These vestments are made of quilted fabric that offer some protection to the wearer. The padded jacket is stitched with %^RESET%^%^ORANGE%^th%^BOLD%^r%^RESET%^%^ORANGE%^ea%^BOLD%^d %^RESET%^%^ORANGE%^of g%^BOLD%^o%^RESET%^%^ORANGE%^ld%^BOLD%^%^WHITE%^ with a %^RESET%^%^MAGENTA%^purple %^BOLD%^%^WHITE%^lining that sometimes flashes as the wearer moves. The pants are simple and form-fitting but flexible enough to avoid restricting movement.%^RESET%^");
        set_short("%^BOLD%^%^WHITE%^Padded white vestments%^RESET%^");
        break;

    case "seija":
        set_long("%^RESET%^These simple vestments have been dyed in to match whatever element the priest favors: %^BOLD%^%^RED%^red %^RESET%^for fire, %^BOLD%^%^BLUE%^blue %^RESET%^for water, %^BOLD%^%^CYAN%^cyan %^RESET%^for air, and %^RESET%^%^ORANGE%^brown %^RESET%^for earth.  The only adornment is a teardrop shaped %^BOLD%^%^WHITE%^crystal %^RESET%^sewn into the chest of the vestments");
        set_short("%^RESET%^simple cotton vestments%^RESET%^");
        break;

    case "khyron":
        set_long("%^BOLD%^%^BLACK%^The vestments of Khyron are made of a pitch black satin that has been shredded and singed in the riotous celebration of the faithful.  The vestments change throughout a priest's life, with a new strip of colored fabric added for each storm or instance of destruction the priest causes - %^BOLD%^%^RED%^red %^BLACK%^for fire, %^YELLOW%^yellow %^BLACK%^for lightning, %^WHITE%^white %^BLACK%^for ice, and %^CYAN%^cyan %^BLACK%^for wind.%^RESET%^");
        set_short("%^BOLD%^%^BLACK%^Pitch black satin vestments%^RESET%^");
        break;

    default:  tell_object(ETO, "Someone forgot your deity," +
                          " please bugreport and let us know who you follow.");
        break;
    }
    //set_ac(myac);
    tell_object(ETO, "%^BOLD%^Your deity blesses you with vestments to help protect you.");
    tell_room(EETO, "%^BOLD%^" + ETOQCN + " is clothed in vestments of " + ETO->QP + " faith.", ETO);
    return 1;
}

int removeit()
{
    tell_room(EETO, "The vestments shimmer slightly as " + ETOQCN + " removes them.", ETO);
    tell_object(ETO, "The vestments shimmers slightly as you remove them.");
    return 1;
}

int save_me(string file)
{
    return 1;
}

int wearable()
{
    return 1;
}
