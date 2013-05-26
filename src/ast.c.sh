#!/bin/bash
tmpfile='ast.c.tmp'

cat c2java.h |
grep -o -P "(?<=extern )ast_(node|stmt|expr) \*.+(?=;)" |
while read sig; do
    echo $sig > $tmpfile
    sed -i -e 's@[,)]@\n@g' $tmpfile
    ret_type=$(cat $tmpfile | grep -o -P '^ast_(node|stmt|expr)')
    var=${ret_type:4:1}
    name=$(cat $tmpfile  | grep -o -P '(?<=\*).+(?=_new\()')
    upper_name=$(echo $name | tr '[:lower:]' '[:upper:]')
    echo $sig
    echo "{"
    echo "    $ret_type *$var = newast(AST_$upper_name);"
    for par in $(cat $tmpfile | grep -o -P '[0-9a-zA-Z_]+$'); do
        echo "    $var->$name.$par = $par;"
    done
    echo "    return $var;"
    echo "}"
    echo ""
done

cat c2java.h |
grep -o -P "(?<=extern )ast_(node|stmt|expr) \*.+(?=;)" |
while read sig; do
    echo $sig > $tmpfile
    sed -i -e 's@[,)]@\n@g' $tmpfile
    name=$(cat $tmpfile  | grep -o -P '(?<=\*).+(?=_new\()')
    echo "struct {"
    for par in $(cat $tmpfile | grep -o -P '(?<=int )[0-9a-zA-Z_]+$'); do
        echo "    int $par;"
    done
    for par in $(cat $tmpfile | grep -o -P '\*[0-9a-zA-Z_]+$'); do
        echo "    struct ast_node $par;"
    done
    echo "} $name;"
    echo ""
done

cat c2java.h |
grep -o -P "(?<=extern )ast_(node|stmt|expr) \*.+(?=;)" |
while read sig; do
    echo $sig > $tmpfile
    sed -i -e 's@[,)]@\n@g' $tmpfile
    name=$(cat $tmpfile  | grep -o -P '(?<=\*).+(?=_new\()')
    upper_name=$(echo $name | tr '[:lower:]' '[:upper:]')
    echo -n "AST_$upper_name, "
done

rm -f $tmpfile
