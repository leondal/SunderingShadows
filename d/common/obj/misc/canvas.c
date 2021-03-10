#include <std.h>

inherit OBJECT;

int painted;
int descd;
int ident;


string query_defdesc()
{
    return "This is a pristine white canvas. The weave is tight and smooth, with no major
imprefections. The cotton appears ready to hold paint well.
%^ORANGE%^<paint %^ORANGE%^%^ULINE%^CANVAS%^RESET%^%^ORANGE%^>%^RESET%^
    Will allow you to paint on CANVAS in your inventory.
%^ORANGE%^<wash %^ORANGE%^%^ULINE%^CANVAS%^RESET%^%^ORANGE%^>%^RESET%^
    Will wash away any painting given CANVAS has, you'll need some strong alcoholic drink. Drink will be wasted. If you're a dwarf you either don't paint or don't make mistakes!";
}

void create()
{
    ::create();

    set_short("a clean canvas");
    set_long(query_defdesc());
    set_id(({ "canvas", "canvasxxx" }));
    set_weight(1);
    set_value(200);
}

void init()
{
    ::init();
    add_action("paint_canvas", "paint");
    add_action("clear_canvas", "wash");
}

int paint_canvas(string str)
{
    string temp;
    temp = "/daemon/filters_d"->filter_colors(str);
    if (!objectp(TO)) {
        return 0;
    }

    if (present(str, TP) != TO) {
        return 0;
    }

    if (painted && !descd) {
        tell_object(TP, "The canvas appears as:\n" + query_long() + "\n");

        tell_object(TP, "%^BOLD%^%^RED%^Choose how painting should appear in your inventory.");
        tell_object(TP, "%^BOLD%^%^RED%^Description must contain one of the following words:%^RESET%^ sketch, picture, painting, drawing");

        input_to("short_desc", TP);
        return 1;
    }

    if (painted) {
        tell_object(TP, "That won't work! Wash painting away with alcohol first!\n");
        return 1;
    }

    write("Now paint your painting. Hit <return> after each line of description.");
    write("** to end painting.");
    input_to("long_desc", TP);
    return 1;
}

void long_desc(string str, object tp, string long){
    if (str == "**") {
        end_long(tp, long);
    } else {
        if (!long) {
            long = str + "\n";
        }else {
            long = long + str + "\n";
        }
        input_to("long_desc", tp, long);
    }
}

end_long(object tp, string long)
{

    if (long) {
        painted = 1;
        TO->set_long(long + "%^RESET%^\n");

    }

    tell_object(tp, "The canvas now appears as:\n" + query_long() + "\n");

    tell_object(tp, "%^BOLD%^%^RED%^Choose how painting should appear in your inventory.");
    tell_object(tp, "%^BOLD%^%^RED%^Description must contain one of the following words:%^RESET%^ sketch, picture, painting, drawing");

    input_to("short_desc", tp);
}

short_desc(string str, object tp)
{
    string temp = strip_colors(str);

    if (strsrch(temp, "painting") == -1 && strsrch(temp, "Painting") == -1 &&
        strsrch(temp, "picture") == -1 && strsrch(temp, "Picture") == -1 &&
        strsrch(temp, "sketch") == -1 && strsrch(temp, "Sketch") == -1 &&
        strsrch(temp, "drawing") == -1 && strsrch(temp, "Drawing") == -1) {
        tell_object(tp, "%^BOLD%^%^RED%^You must include one of these words: sketch, picture, painting, drawing");
        tell_object(tp,"%^BOLD%^%^RED%^Paint this canvas again to continue this step.");
            return 1;
        }

    TO->set_short(str + "%^RESET%^");
    TO->add_id(lower_case(strip_colors(str)));
    TO->add_id(strip_colors(str));
    tell_object(tp, "The canvas now appears as:\n" + str + "\n");
    descd = 1;
    return 1;
}



int clear_canvas(string str)
{
    object * alcohols;

    if (!objectp(TO)) {
        return 0;
    }

    if (present(str, TP) != TO) {
        return 0;
    }

    if (!(painted || descd)) {
        write("%^BOLD%^That canvas is still empty!");
        return 1;
    }

    alcohols = filter_array(filter_array(all_inventory(TP), (:$1->query_type() == "alcoholic":)), (:$1->query_strength() > 35:));
    if(!sizeof(alcohols)){
        tell_object(TP,"%^BOLD%^You don't have sufficiently strong alcohol to wash this painting away!");
        return 1;
    }

    alcohols[0]->remove();

    tell_object(TP,"%^BOLD%^You take your time washing painting with alcohol.");
    tell_room(ETP, "%^BOLD%^" + TP->QCN + " clears away painting with some alcohol.", TP);

    set_short("an almost clean canvas");
    set_long(query_defdesc());
    painted = 0;
    descd = 0;

    return 1;
}
