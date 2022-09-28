function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "love.........."
        a[2] = "whats this dumbass sticker i love you too <3"
        a[3] = "send me more!!!"
        a[4] = "<3"
        a[5] = "i love you... <3"
        a[6] = "i love you so much <3 <3 <3"
        a[7] = "i bet youre lying."
        a[8] = "no takebacks! you WILL love me forever."
        a[9] = "not that i think you would but if you cheat on me ill kill you."
        a[10] = "say it again! say it 999999999 more times!"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end