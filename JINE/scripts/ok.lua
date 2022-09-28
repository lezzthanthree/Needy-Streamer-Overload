function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "ok"
        a[2] = "k"
        a[3] = "as long as you understand"
        a[4] = "potassium"
        a[5] = "youre just all talk huh."
        a[6] = "wow talk about no effort"
        a[7] = "are you suuure?"
        a[8] = "(*'-')b"
        a[9] = "do you even know what youre OKing at"
        a[10] = "thanks for the zero effort"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end