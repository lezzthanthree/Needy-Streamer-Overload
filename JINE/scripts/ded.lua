function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "officer we got a dead nerd here",
                "dont die...",
                "I CAST PHOENIX DOWN",
                "oh no... theres no pulse.......",
                "(pokes your limp body with my foot)",
                "we'll be together in our next life too right? :(",
                "nerds die so easily",
                "NO DONT DIE ON ME",
                "if you die i die",
                 "youd better not die before i do!!!",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end