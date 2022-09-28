function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "officer we got a dead nerd here"
        a[2] = "dont die..."
        a[3] = "I CAST PHOENIX DOWN"
        a[4] = "oh no... theres no pulse......."
        a[5] = "(pokes your limp body with my foot)"
        a[6] = "we'll be together in our next life too right? :("
        a[7] = "nerds die so easily"
        a[8] = "NO DONT DIE ON ME"
        a[9] = "if you die i die"
        a[10] = "youd better not die before i do!!!"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end