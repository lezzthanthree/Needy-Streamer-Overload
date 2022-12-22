function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "ok",
                "k",
                "as long as you understand",
                "potassium",
                "youre just all talk huh.",
                "wow talk about no effort",
                "are you suuure?",
                "(*'-')b",
                "do you even know what youre OKing at",
                 "thanks for the zero effort",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end