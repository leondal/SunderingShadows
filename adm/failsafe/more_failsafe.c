/*
    /std/user/more.c
    from Nightmare IV
    inherited player functions for paging files and string arrays
    created by Descartes of Borg 931204
*/

#define DEFAULT_MORE "%^BOLD%^%^BLACK%^%^B_WHITE%^"
#define TO this_object()
static private mapping __More;

void do_more(string str);
void do_help();

void create() { __More = ([]); }

void fixmore(){ __More = ([]);}
varargs int more(mixed what, string cl, function endmore) {
    string *tmp;

    if(!pointerp(what) && !stringp(what))
      return notify_fail("Unknown file reference.\n");
    if(__More["lines"]) return notify_fail("You are in more now.\n");
    if(!(__More["class"] = cl)) __More["class"] = "info";
    if(!(__More["screen"]=atoi((string)this_object()->getenv("LINES"))))
      __More["screen"] = 20;
    if(stringp(what)) {
        if(sizeof(tmp = (string *)this_object()->wild_card(what)) != 1)
          return notify_fail("Ambiguous file reference.\n");
        if(file_size(tmp[0]) < 1)
          return notify_fail("Ambiguous file reference.\n");
        __More["total"] = sizeof(__More["lines"] =
          explode(read_file(tmp[0]), "\n"));
    }
    else if(pointerp(what))
      __More["total"] = sizeof(__More["lines"] = what);
    else return notify_fail("Illegal file reference.\n");
    if(wizardp(this_object()) && tmp && tmp[0])
      message(__More["class"], "--==** "+tmp[0]+" **==--", this_object());
    if(!__More["total"]) {
        __More = ([]);
        if(functionp(endmore)) (*endmore)();
        return 1;
    }
    __More["current"] = 0;
    if(functionp(endmore)) __More["endfun"] = endmore;
    do_more(" ");
    return 1;
}

static void do_more(string cmd) {
    string arg;
    string *matches;
    int i;

    if(!cmd || cmd == "") cmd = " ";
    if((i=strlen(cmd)) > 1) arg = cmd[1..(i-1)];
    else arg = "";
    switch(cmd = cmd[0..0]) {
        case " ": break;
        case "b": case "B":
          __More["current"] -= __More["screen"]*2;
          if(__More["current"] < 0) __More["current"] = 0;
          break;
        case "<": __More["current"] = 0; break;
        case ">": __More["current"] = __More["total"]-1; break;
        case "/":
          __More["regexp"] = cmd+arg;
          if(!sizeof(matches=regexp(__More["lines"][__More["current"]..__More["total"]-1], arg))) {
            message(__More["class"], "Pattern not found.", this_object());
            input_to("do_more");
            return;
          }
          for(i=__More["current"]; i<__More["total"]; i++) {
            if(__More["lines"][i] != matches[0]) continue;
            __More["current"] = i;
            break;
          }
          message(__More["class"], "Skipping to line "+
            __More["current"]+"...", this_object());
          do_more(" ");
          return;
        case "?":
          __More["regexp"] = cmd+arg;
          if(!sizeof(matches=regexp(__More["lines"][0..__More["current"]], arg))) {
            message(__More["class"], "Pattern not found.", this_object());
            input_to("do_more");
            return;
          }
          __More["current"] = member_array(matches[0],
            __More["lines"][0..__More["current"]]);
          message(__More["class"], "...Backing up..", this_object());
          do_more(" ");
          return;
        case "n":
          if(!__More["regexp"] || __More["regexp"] == "") {
            message(__More["class"], "No previous search.", this_object());
            input_to("do_more");
            return;
          }
          do_more(__More["regexp"]);
          return;
        case "=":
          message(__More["class"], "Current line: "+
            __More["current"], this_object());
          input_to("do_more");
          return;
        case "v": case "V":
          message(__More["class"], "Nightmare Mudlib \"more\" "+
            "version 2.0 by Descartes of Borg 931204.", this_object());
          input_to("do_more");
          return;
        case "h": case "H": do_help(); input_to("do_more"); return;
        case "Q": case "q":
          message("N"+__More["class"], "\n", this_object());
          if(functionp(__More["endfun"])) (*__More["endfun"])();
          __More = ([]);
          return;
        default:
          message(__More["class"], "Unrecognized command.", this_object());
          input_to("do_more");
          return;
    }
    message("N"+__More["class"], "\n", this_object());
    for(i=__More["current"];
      i<__More["current"] + __More["screen"]; i++) {
        if(i>= __More["total"]) {
          if(functionp(__More["endfun"])) (*__More["endfun"])();
          __More = ([]);
          return;
        }
        message(__More["class"], __More["lines"][i], this_object());
    }
    if((__More["current"] = i) >= __More["total"]) {
        if(functionp(__More["endfun"])) (*__More["endfun"])();
        __More = ([]);
        return;
    }
    __More["current"] = i;
  // Various fixes below. Changed class from Ninfo to Nprompt to make the
  // more prompt really bold black on my crappy text terminal, I couldn't
  // be the only one suffering from that...
  // Garrett.
//    message("prompt", DEFAULT_MORE+"--More-- ("+
    message("prompt", ((string)TO->getenv("MOREPREFIX")?(string)TO->getenv("MOREPREFIX"):DEFAULT_MORE) +
             "--More-- ("+ 
      to_int(percent(__More["current"], __More["total"]))+"%) %^RESET%^", this_object());
    input_to("do_more");
    return;
}

void do_help() {
    message("Nhelp",
      "Help for the \"more\" utility:\n\n"
      "<spacebar> Display the next page of text.\n"
      "B or b     Display the previous page of text.\n"
      "<          Goto the beginning of the document.\n"
      ">          Goto the end of the document.\n"
      "=          Display the current line number.\n"
      "/\<exp>     Goto the next line with the expression <exp> in it.\n"
      "?<exp>     Goto the previous line with the expression <exp> in it.\n"
      "v or V     See the version information about this pager.\n"
      "h or H     This help screen.\n"
      "q or Q     Quit out of the pager.\n", this_object()
    );
}
