varargs string format_page(string * items, int columns, int scrwidth, int vertical)
{
    int width, i, j, x;
    string ret;

    if (vertical) {
        return format_page_v(items, columns, scrwidth);
    }

    if (!columns) {
        columns = 2;
    }
    if (!scrwidth) {
        scrwidth = 72;
    }

    ret = "";
    width = scrwidth / columns;
    for (i = 0, x = sizeof(items); i < x; i += columns) {
        for (j = 0; j < columns; j++) {
            if (i + j >= x) {
                break;
            }
            ret += arrange_string(items[i + j], width);
        }
        ret += "\n";
    }
    return ret;
}

varargs string format_page_v(string* items, int columns, int scrwidth)
{

    int width;
    int i, j;
    int column_height;
    string ret = "";

    if (!columns) {
        columns = 2;
    }
    if (!scrwidth) {
        scrwidth = 72;
    }

    column_height = sizeof(items) / columns + sizeof(items) % columns;
    width = scrwidth / columns;

    for (j = 0; j < column_height; j++ )
    {
        for (i = 0; i < (columns); i++ )
        {
            if ((i * column_height + j) >= sizeof(items)) {
                break;
            }
            ret += arrange_string(items[i * column_height + j], width);
        }
        ret += "\n";

    }
    return ret;
}

string auto_format_page(string *output, object player)
{
    int y, z;
    int columns;
    int scrw = atoi(player->getenv("SCREEN"));
    int scrl = atoi(player->getenv("LINES"));
    int vertical = player->getenv("VCOLUMNS") ? 1 : 0;
    int i;
    string result;

    // "Best fit columns algorithm"

    // Maximum width of the column
    z = max(map(output, (:sizeof(strip_colors($1)):))) + 2;

    // We don't support pretty output on terminals too thin in both directions
    scrw = scrw ? scrw : 72;
    scrw = scrw > 34 ? scrw : 34;
    scrl = scrl ? scrl : 20;
    scrl = scrl > 6 ? scrl : 6;

    // Columns setting set by user
    y = atoi(player->getenv("COLUMNS"));
    y = y < 1 ? 1 : y;

    // How many times output string fits in current screen width?
    columns = scrw / z;
    columns = columns < 1 ? 1 : columns;

    // If that value is more than columns setting, it will be
    // maximum used and user will see less columns than they
    // have set.
    columns = columns > y ? y : columns;

    // Recalculating best fit screen width to arrange by the left edge.
    scrw = z * columns;

    // Location data is small, no buffering is necessary, we can just output it.
    result = "";

    while(i < sizeof(output))
    {
        result += format_page(output[i..(i + columns * scrl - 1)], columns, scrw, vertical);
        i += columns * scrl;
        if (i < sizeof(output)) {
            result += "%^RESET%^---\n";
        }

    }

    return result;

}
