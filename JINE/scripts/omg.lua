function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "RIGHT??? i knew youd understand",
                "i am da best",
                "right???",
                "keep the praise coming!!!",
                "yeees i am the best in the world",
                "hehe. piece of cake for me!",
                "ame is the best",
                "G for GENIUS!!!!!!",
                "you really just OMG at anything huh",
                "now tell me youll never leave your awesome girlfriend!",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end