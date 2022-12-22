function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "ugh. worst reply",
                "were you even paying attention???",
                "ugh",
                "tell me you werent paying attention without telling me you werent paying attention.",
                "i hate that sticker",
                "low effort response 0/10",
                "i hate people who just send one word replies!!!",
                "THIS what huh???",
                "can you put some effort into replying please",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end