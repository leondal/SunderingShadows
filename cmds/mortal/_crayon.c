#include <daemons.h>

string scheme_name, back_color, *common_colors, *rare_colors;
int scatter;

int cmd_crayon(string str) {
    string uncolored, colored, *args;
    int argsize;
    mapping scheme = ([]), schemes = ([]);

    if(!str) {
        help();
        return 1;
    }

    args = explode(str, " ");
    argsize = sizeof(args);

    if(argsize < 2) {
        help();
        return 1;
    }

    if(args[0] == "scheme") {
        if(args[1] == "list") {
            string *scheme_names, *scheme_list = ({});
            schemes = CRAYON_D->query_schemes(TP->query_name());

            if(!sizeof(schemes)) {
                return notify_fail("You have no saved color schemes.");
            }

            scheme_names = keys(schemes);
            foreach(scheme_name in scheme_names) {
                scheme = schemes[scheme_name];
                scheme_list += ({ "%^RESET%^%^CRST%^" + CRAYON_D->color_string(scheme_name, "", ({}), scheme, ({}), 1) + "%^CRST%^%^RESET%^" });
            }

            tell_object(TP,"Saved color schemes: "+implode(scheme_list,", "));
            return 1;
        }

        if(argsize != 3) {
            help();
            return 1;
        }

        scheme_name = args[2];
        if(scheme_name == "scheme") {
            return notify_fail("The value 'scheme' can not used as color scheme name.\n");
        }

        if(args[1] == "save") {
            schemes = CRAYON_D->query_schemes(TP->query_name());

            if(sizeof(schemes) >= 50) {
                return notify_fail(
                    "You can not have more than 50 saved color schemes. \n"
                    "A previously saved color scheme will need to be removed before you can add a new one.\n"
                );
            }

            write("Enter the color code for the base color. This color will be used for the majority of words.  Entering '**' will abort the process.\n");
            input_to("enter_back_color");
            return 1;
        }

        if(args[1] == "remove") {
            if(CRAYON_D->remove_scheme(TP->query_name(), scheme_name)) {
                tell_object(TP,"Removed color scheme: "+scheme_name);
                return 1;
            }
            return notify_fail("That is not a valid color scheme to remove.");
        }
        help();
        return 1;
    }

    //do coloring with scheme stuff
    scheme_name = args[0];
    uncolored = implode(args[1..argsize-1], " ");
    schemes = CRAYON_D->query_schemes(TP->query_name());
    scheme = schemes[scheme_name];

    colored = CRAYON_D->color_string(uncolored, "", ({}), scheme, ({}), 1);

    colored = "%^RESET%^%^CRST%^" + colored + "%^CRST%^%^RESET%^";

    printf("%s\n\n",colored);
    write(colored+"\n");
    return 1;
}

void enter_back_color(string str) {
    if(!str || str == ""){
        write("Invalid color code.\nEnter the color code for the base color. This color will be used for the majority of words.  Entering '**' will abort the process.\n");
        input_to("enter_back_color");
        return;
    }
    if(str == "**") {
        write("Color scheme creation halted. No color scheme has been saved.");
        return;
    }
    if(!(str[0..1] ==  "%^") || !(str[<2..] == "%^")) {
        write("Invalid color code.\nEnter the color code for the base color. This color will be used for the majority of words.  Entering '**' will abort the process.\n");
        input_to("enter_back_color");
        return;
    }
    back_color = str;
    write("Enter the commonly used color codes for the color scheme seperated by commas. \n(%%%^^^RED%%%^^^,%%%^BLUE%%%^^^,%%%^^^GREEN%%%^^^)\n");
    input_to("enter_common_colors");
}

void enter_common_colors(string str) {
    string color;
    if(!str || str == ""){
        write("One or more invalid color codes.\nEnter the commonly used color codes for the color scheme seperated by commas. \n(%%%^^^RED%%%^^^,%%%^BLUE%%%^^^,%%%^^^GREEN%%%^^^)\n");
        input_to("enter_common_colors");
        return;
    }
    if(str == "**") {
        write("Color scheme creation halted. No color scheme has been saved.");
        return;
    }
    common_colors = explode(str,",");
    foreach(color in common_colors) {
        if(!(color[0..1] ==  "%^") || !(color[<2..] == "%^")) {
            write("One or more invalid color codes.\nEnter the commonly used color codes for the color scheme seperated by commas. \n(%%%^^^RED%%%^^^,%%%^BLUE%%%^^^,%%%^^^GREEN%%%^^^)\n");
            input_to("enter_common_colors");
            return;
        }
    }
    write("Enter the rarely used color codes for the color scheme seperated by commas. \n(%%%^^^RED%%%^^^,%%%^BLUE%%%^^^,%%%^^^GREEN%%%^^^)\n");
    input_to("enter_rare_colors");
}

void enter_rare_colors(string str) {
    string color;
    if(!str || str == "") {
        write("One or more invalid color codes.\nEnter the rarely used color codes for the color scheme seperated by commas. \n(%%%^^^RED%%%^^^,%%%^BLUE%%%^^^,%%%^^^GREEN%%%^^^)\n");
        input_to("enter_rare_colors");
        return;
    }
    if(str == "**") {
        write("Color scheme creation halted. No color scheme has been saved.");
        return;
    }
    rare_colors = explode(str,",");
    foreach(color in rare_colors) {
        if(!(color[0..1] ==  "%^") || !(color[<2..] == "%^")) {
            write("One or more invalid color codes.\nEnter the rarely used color codes for the color scheme seperated by commas. \n(%%%^^^RED%%%^^^,%%%^BLUE%%%^^^,%%%^^^GREEN%%%^^^)\n");
            input_to("enter_rare_colors");
            return;
        }
    }
    write("Enter the scatter rate of the colors (scale of 1 to 10,  the higher the scatter the higher the chance and rate of multicolored words).\n");
    input_to("enter_scatter");
}

void enter_scatter(string str) {
    mapping scheme = ([]);
    if(!str || str == "") {
        write("Invalid scatter rate\nEnter the scatter rate of the colors (scale of 1 to 10, the higher the scatter the higher the chance and rate of multicolored words).\n");
        input_to("enter_scatter");
        return;
    }
    if(str == "**") {
        write("Color scheme creation halted. No color scheme has been saved.");
        return;
    }
    if(!regexp(str, "[1-9]|10+")) {
        write("Invalid scatter rate.\nEnter the scatter rate of the colors (scale of 1 to 10,  the higher the scatter the higher the chance and rate of multicolored words).\n");
        input_to("enter_scatter");
        return;
    }
    scatter = to_int(str);
    scheme["back color"] = back_color;
    scheme["common colors"] = common_colors;
    scheme["rare colors"] = rare_colors;
    scheme["scatter"] = scatter;
    CRAYON_D->save_scheme(TP->query_name(), scheme_name, scheme);
    tell_object(TP, "Color scheme saved as: " + scheme_name );
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

crayon - apply color schemes to a string of text

%^CYAN%^SYNOPSIS%^RESET%^

crayon scheme [save|remove] %^ORANGE%^%^ULINE%^SCHEMENAME%^RESET%^
crayon scheme list
crayon %^ORANGE%^%^ULINE%^SCHEMENAME%^RESET%^ %^ORANGE%^%^ULINE%^TEXT%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command allows a player to define color schemes and then use them to apply colors to a string of text, which outputs the colored results and the string of text with color codes.

%^ORANGE%^<crayon scheme [save|remove] %^ORANGE%^%^ULINE%^SCHEMENAME%^RESET%^%^ORANGE%^>%^RESET%^

Will save|remove a color scheme named %^ORANGE%^%^ULINE%^SCHEMENAME%^RESET%^. A player can save up to 50 color schemes.

%^ORANGE%^<crayon scheme list>%^RESET%^

Will list all previously created color schemes.

%^ORANGE%^<crayon %^ORANGE%^%^ULINE%^SCHEMENAME%^RESET%^ %^ORANGE%^%^ULINE%^TEXT%^RESET%^%^ORANGE%^>%^RESET%^

Will apply the color scheme named %^ORANGE%^%^ULINE%^SCHEMENAME%^RESET%^ to the string of text %^ORANGE%^%^ULINE%^TEXT%^RESET%^ and output the colored string of TEXT and the string of TEXT with color codes for copy/paste.

%^CYAN%^SEE ALSO%^RESET%^

color, emote, emoteat

");
}
