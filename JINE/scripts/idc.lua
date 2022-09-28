function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "YOU SHOULD CARE!!!"
        a[2] = "^o^"
        a[3] = "how can you not care about what your girlfriend says?!"
        a[4] = "that really hurt p-chan :( jk i dont care either"
        a[5] = "yes i can tell"
        a[6] = "can you be serious!!!"
        a[7] = "fine if you dont care then it's over between us just kidding i would never leave you..."
        a[8] = "youre looking real punchable rn you know"
        a[9] = "you will not know peace."
        a[10] = "FINE im gonna go cry in the arms of my darling nerds instead!!!!!!!...jk youre so much better"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end