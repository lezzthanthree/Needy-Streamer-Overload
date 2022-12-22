function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "never forgive you i will",
                "i will NEVER forgive you",
                "hmm.... ok i forgive you!!",
                "i guess i could forgive you...",
                "buy me some ice cream and ill forgive you",
                "send me a selfie of you groveling for forgiveness",
                "thats ok! (see im so nice)",
                "is that all it takes for you to get down on your knees?",
                "i forgive you! NOT!!!!!",
                "soz for making you say soz",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end