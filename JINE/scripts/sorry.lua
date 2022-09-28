function Initialize()
    -- add a new ame JINE chat here.
        a = {}
        a[1] = "never forgive you i will"
        a[2] = "i will NEVER forgive you"
        a[3] = "hmm.... ok i forgive you!!"
        a[4] = "i guess i could forgive you..."
        a[5] = "buy me some ice cream and ill forgive you"
        a[6] = "send me a selfie of you groveling for forgiveness"
        a[7] = "thats ok! (see im so nice)"
        a[8] = "is that all it takes for you to get down on your knees?"
        a[9] = "i forgive you! NOT!!!!!"
        a[10] = "soz for making you say soz"
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end