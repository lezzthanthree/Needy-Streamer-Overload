function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "love..........",
                "whats this dumbass sticker i love you too <3",
                "send me more!!!",
                "<3",
                "i love you... <3",
                "i love you so much <3 <3 <3",
                "i bet youre lying.",
                "no takebacks! you WILL love me forever.",
                "not that i think you would but if you cheat on me ill kill you.",
                "say it again! say it 999999999 more times!",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end