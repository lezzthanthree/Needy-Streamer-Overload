function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "ugh. worst reply"
        a[2] = "were you even paying attention???"
        a[3] = "ugh"
        a[4] = "tell me you werent paying attention without telling me you werent paying attention."
        a[5] = "i hate that sticker"
        a[6] = "low effort response 0/10"
        a[7] = "i hate people who just send one word replies!!!"
        a[8] = "THIS what huh???"
        a[9] = "can you put some effort into replying please"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end