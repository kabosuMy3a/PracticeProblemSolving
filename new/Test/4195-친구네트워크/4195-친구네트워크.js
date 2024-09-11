const fs = require("fs");
const Tests = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");
const T = parseInt(Tests[0]);

let cur_line_num = 1 ;

function find(fKey, map){
    if(map.get(fKey).parent === fKey){
        return fKey
    }
    const parentKey = find(map.get(fKey).parent, map)
    const curVal = map.get(fKey);
    map.set(fKey, {parent:parentKey, num: curVal.num });
    return parentKey;
}

function union(f1Key, f2Key, map){
    const f1ParentKey = find(f1Key,map);
    const f2ParentKey = find(f2Key,map);

    const f1ParentVal = map.get(f1ParentKey);
    const f2ParentVal = map.get(f2ParentKey);

    if(f1ParentKey < f2ParentKey){
        map.set(f2ParentKey, {
            parent: f1ParentKey,
            num : 1
        })
        map.set(f1ParentKey, {
            parent: f1ParentKey,
            num : f1ParentVal.num + f2ParentVal.num
        })
    } else {
        map.set(f1ParentKey, {
            parent: f2ParentKey,
            num : 1
        })
        map.set(f2ParentKey, {
            parent: f2ParentKey,
            num : f1ParentVal.num + f2ParentVal.num
        })
    }
}


for(let t = 0 ; t < T ; t++){
    const N = parseInt(Tests[cur_line_num]);
    const arr = Tests.slice(cur_line_num + 1,  cur_line_num + 1 + N).map((each) => each.split(" "));
    cur_line_num += 1 + N;

    const map = new Map();
    for(let [f1Key, f2Key] of arr){
        let f1Val = map.get(f1Key)
        let f2Val = map.get(f2Key)
        if(!f1Val){
            f1Val = {parent: f1Key, num: 1}
            map.set(f1Key, f1Val);
        }

        if(!f2Val){
            f2Val = {parent: f2Key, num: 1}
            map.set(f2Key, f2Val);
        }

        if(find(f1Key, map) !== find(f2Key, map)) {
            union(f1Key, f2Key, map);
        }

        const unifiedF1ParentVal = map.get(find(f1Key, map));
        console.log(unifiedF1ParentVal.num)
    }
}
