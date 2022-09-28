function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "RIGHT??? i knew youd understand"
        a[2] = "i am da best"
        a[3] = "right???"
        a[4] = "keep the praise coming!!!"
        a[5] = "yeees i am the best in the world"
        a[6] = "hehe. piece of cake for me!"
        a[7] = "ame is the best"
        a[8] = "G for GENIUS!!!!!!"
        a[9] = "you really just OMG at anything huh"
        a[10] = "now tell me youll never leave your awesome girlfriend!"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end