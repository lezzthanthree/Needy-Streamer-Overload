function Update()
    local ip = SKIN:GetMeasure('measureIP'):GetStringValue()
    if ip == 'N/A' then
        SKIN:Bang('!SetVariable', 'MaskedIP', 'N/A')
    else
        -- Замаскируем IP адрес
        local masked_ip = ip:gsub("(%d)%.(%d)%.(%d)%.(%d)", "%1.**.**.**")
        SKIN:Bang('!SetVariable', 'MaskedIP', masked_ip)
    end
end
