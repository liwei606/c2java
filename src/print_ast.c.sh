#!/bin/bash
tmpfile='print_ast.c.tmp'

cat c2java.h |
grep -o -P "(?<=extern )ast_(node|stmt|expr) \*.+(?=;)" |
while read sig; do
    echo $sig > $tmpfile
    sed -i -e 's@[,)]@\n@g' $tmpfile
    name=$(cat $tmpfile  | grep -o -P '(?<=\*).+(?=_new\()')
    upper_name=$(echo $name | tr '[:lower:]' '[:upper:]')
    echo "g_ast_printers[AST_$upper_name] = print_$name;"
done

cat c2java.h |
grep -o -P "(?<=extern )ast_(node|stmt|expr) \*.+(?=;)" |
while read sig; do
    echo $sig > $tmpfile
    sed -i -e 's@[,)]@\n@g' $tmpfile
    name=$(cat $tmpfile  | grep -o -P '(?<=\*).+(?=_new\()')
    upper_name=$(echo $name | tr '[:lower:]' '[:upper:]')
    echo ""
    echo "static void print_$name(ast_node *n)"
    echo "{"
    echo "    printf(\"<ul>\n\");"
    echo "    printf(\"<li>$name</li>\n\");"
    for par in $(cat $tmpfile | grep -o -P '(?<=int )[0-9a-zA-Z_]+$'); do
        echo "    printf(\"<li>$par: %d</li>\n\", n->$name.$par);"
    done
    for par in $(cat $tmpfile | grep -o -P '(?<=\*)[0-9a-zA-Z_]+$'); do
        echo "    printf(\"<li>$par:\n\");"
        echo "    print_ast(n->$name.$par);"
        echo "    printf(\"</li>\n\");"
    done
    echo "    printf(\"</ul>\n\");"
    echo "}"
done

rm -f $tmpfile
