#include <std.h>

int cmd_fixspells(string str){
    TP->resetMemorized();
    TP->InitInnate();
    tell_object(TP, "Done");
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

fixspells - attempt to fix your spells

%^CYAN%^DESCRIPTION%^RESET%^

This command will reset your memorized spells and re-init innate spells. Use it if your memorized spell list %^ORANGE%^<recall %^ORANGE%^%^ULINE%^CLASS%^RESET%^%^ORANGE%^ spells>%^RESET%^ or innate spell list %^ORANGE%^<recall innate spells>%^RESET%^ looks wrong.

%^CYAN%^SEE ALSO%^RESET%^

fixmore, fixroom, feats fix, recall, spells

");
}
